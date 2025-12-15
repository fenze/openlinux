#include <asm/vdso.h>
#include <elf.h>
#include <string.h>
#include <sys/auxv.h>

void __init_vdso(void)
{
	Elf64_Ehdr *ehdr = (Elf64_Ehdr *)getauxval(AT_SYSINFO_EHDR);
	Elf64_Phdr *phdr = (Elf64_Phdr *)(ehdr + ehdr->e_phoff);

	for (int i = 0; i < ehdr->e_phnum; i++) {
		Elf64_Dyn *dyn;
		Elf64_Sym *symtab;
		const char *strtab;

		if (phdr[i].p_type == PT_DYNAMIC) {
			Elf64_Sym *sym;

			dyn = (Elf64_Dyn *)((char *)ehdr + phdr[i].p_offset);
			symtab = 0;
			strtab = 0;

			while (dyn->d_tag != DT_NULL) {
				if (dyn->d_tag == DT_STRTAB) {
					strtab = (const char *)(ehdr + dyn->d_un.d_ptr);
				} else if (dyn->d_tag == DT_SYMTAB) {
					symtab = (Elf64_Sym *)(ehdr + dyn->d_un.d_ptr);
				}

				if (strtab && symtab) {
					break;
				}

				dyn++;
			}

			sym = symtab;
			while ((char *)sym < strtab) {
				if (sym->st_name != 0 && sym->st_value != 0) {
					const char *name = strtab + sym->st_name;

					for (int i = 0; __vdso_symtab[i].name != 0; i++) {
						if (strcmp(name, __vdso_symtab[i].name) == 0) {
							__vdso_symtab[i].func = (void *)(ehdr + sym->st_value);
							break;
						}
					}
				}

				sym = (Elf64_Sym *)((char *)sym + sizeof(Elf64_Sym));
			}

			break;
		}
	}
}
