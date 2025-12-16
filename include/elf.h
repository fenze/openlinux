#ifndef __ELF_H
#define __ELF_H

#include <stdint.h>

#define ELF32_ST_BIND(val) (((unsigned char)(val)) >> 4)
#define ELF32_ST_TYPE(val) ((val) & 0xf)

#define ELF64_ST_BIND(val) ELF32_ST_BIND(val)
#define ELF64_ST_TYPE(val) ELF32_ST_TYPE(val)

#define PT_NULL	   0
#define PT_LOAD	   1
#define PT_DYNAMIC 2
#define PT_INTERP  3
#define PT_NOTE	   4
#define PT_SHLIB   5
#define PT_PHDR	   6
#define PT_TLS	   7
#define PT_LOOS	   0x60000000
#define PT_HIOS	   0x6fffffff
#define PT_LOPROC  0x70000000
#define PT_HIPROC  0x7fffffff

#define ET_NONE	  0
#define ET_REL	  1
#define ET_EXEC	  2
#define ET_DYN	  3
#define ET_CORE	  4
#define ET_LOPROC 0xff00
#define ET_HIPROC 0xffff

#define EM_NONE	 0
#define EM_M32	 1
#define EM_SPARC 2
#define EM_386	 3
#define EM_68K	 4
#define EM_88K	 5

#define EM_860 7

#define EM_PARISC      15
#define EM_SPARC32PLUS 18
#define EM_PPC	       20
#define EM_PPC64       21
#define EM_S390	       22
#define EM_SH	       42

#define EM_H8_300H 47
#define EM_H8S	   48

#define EM_X86_64 62
#define EM_CRIS	  76
#define EM_V850	  87

#define DT_NULL	    0
#define DT_NEEDED   1
#define DT_PLTRELSZ 2
#define DT_PLTGOT   3
#define DT_HASH	    4
#define DT_STRTAB   5
#define DT_SYMTAB   6
#define DT_RELA	    7
#define DT_RELASZ   8
#define DT_RELAENT  9
#define DT_STRSZ    10
#define DT_SYMENT   11
#define DT_INIT	    12
#define DT_FINI	    13
#define DT_SONAME   14
#define DT_RPATH    15
#define DT_SYMBOLIC 16
#define DT_REL	    17
#define DT_RELSZ    18
#define DT_RELENT   19
#define DT_PLTREL   20
#define DT_DEBUG    21
#define DT_TEXTREL  22
#define DT_JMPREL   23
#define DT_LOPROC   0x70000000
#define DT_HIPROC   0x7fffffff

#define PF_X 0x1
#define PF_W 0x2
#define PF_R 0x4

#define SHT_NULL     0
#define SHT_PROGBITS 1
#define SHT_SYMTAB   2
#define SHT_STRTAB   3
#define SHT_RELA     4
#define SHT_HASH     5
#define SHT_DYNAMIC  6
#define SHT_NOTE     7
#define SHT_NOBITS   8
#define SHT_REL	     9
#define SHT_SHLIB    10
#define SHT_DYNSYM   11
#define SHT_NUM	     12
#define SHT_LOPROC   0x70000000
#define SHT_HIPROC   0x7fffffff
#define SHT_LOUSER   0x80000000
#define SHT_HIUSER   0xffffffff

#define SHF_WRITE     0x00000001
#define SHF_ALLOC     0x00000002
#define SHF_EXECINSTR 0x00000004
#define SHF_TLS	      0x00000400
#define SHF_MASKPROC  0xf0000000

#define SHN_UNDEF     0x0000
#define SHN_LORESERVE 0xff00
#define SHN_LOPROC    0xff00
#define SHN_HIPROC    0xff1f
#define SHN_ABS	      0xfff1
#define SHN_COMMON    0xfff2
#define SHN_HIRESERVE 0xffff

#define STN_UNDEF 0

#define EI_NIDENT 16

#define EI_MAG1	   1
#define EI_MAG2	   2
#define EI_MAG3	   3
#define EI_CLASS   4
#define EI_DATA	   5
#define EI_VERSION 6
#define EI_OSABI   7
#define EI_PAD	   8

#define ELFMAG1 'E'
#define ELFMAG2 'L'
#define ELFMAG3 'F'
#define ELFMAG	"\177ELF"
#define SELFMAG 4

#define ELFCLASS32  1
#define ELFCLASS64  2
#define ELFCLASSNUM 3

#define ELFDATA2LSB 1
#define ELFDATA2MSB 2

#define EV_CURRENT 1
#define EV_NUM	   2

#define ELFOSABI_NONE  0
#define ELFOSABI_LINUX 3

#define AT_NULL	  0
#define AT_IGNORE 1
#define AT_EXECFD 2
#define AT_PHDR	  3
#define AT_PHENT  4
#define AT_PHNUM  5
#define AT_PAGESZ 6
#define AT_BASE	  7
#define AT_FLAGS  8
#define AT_ENTRY  9
#define AT_NOTELF 10
#define AT_UID	  11
#define AT_EUID	  12
#define AT_GID	  13
#define AT_EGID	  14
#define AT_CLKTCK 17

#define AT_PLATFORM 15
#define AT_HWCAP    16

#define AT_FPUCW 18

#define AT_DCACHEBSIZE 19
#define AT_ICACHEBSIZE 20
#define AT_UCACHEBSIZE 21

#define AT_IGNOREPPC 22

#define AT_SECURE 23

#define AT_BASE_PLATFORM 24

#define AT_RANDOM 25

#define AT_HWCAP2 26

#define AT_RSEQ_FEATURE_SIZE 27
#define AT_RSEQ_ALIGN	     28

#define AT_HWCAP3 29
#define AT_HWCAP4 30

#define AT_EXECFN 31

#define AT_SYSINFO	32
#define AT_SYSINFO_EHDR 33

#define AT_L1I_CACHESHAPE 34
#define AT_L1D_CACHESHAPE 35
#define AT_L2_CACHESHAPE  36
#define AT_L3_CACHESHAPE  37

#define AT_L1I_CACHESIZE     40
#define AT_L1I_CACHEGEOMETRY 41
#define AT_L1D_CACHESIZE     42
#define AT_L1D_CACHEGEOMETRY 43
#define AT_L2_CACHESIZE	     44
#define AT_L2_CACHEGEOMETRY  45
#define AT_L3_CACHESIZE	     46
#define AT_L3_CACHEGEOMETRY  47

#define AT_MINSIGSTKSZ 51

typedef uint16_t Elf32_Half;
typedef int16_t Elf32_SHalf;
typedef uint32_t Elf32_Word;
typedef int32_t Elf32_Sword;
typedef uint64_t Elf32_Xword;
typedef int64_t Elf32_Sxword;

typedef uint32_t Elf32_Off;
typedef uint32_t Elf32_Addr;
typedef uint16_t Elf32_Section;

typedef uint16_t Elf64_Half;
typedef int16_t Elf64_SHalf;
typedef uint32_t Elf64_Word;
typedef int32_t Elf64_Sword;
typedef uint64_t Elf64_Xword;
typedef int64_t Elf64_Sxword;

typedef uint64_t Elf64_Off;
typedef uint64_t Elf64_Addr;
typedef uint16_t Elf64_Section;

typedef struct elf32_dyn {
	Elf32_Sword d_tag;
	union {
		Elf32_Sword d_val;
		Elf32_Addr d_ptr;
	} d_un;
} Elf32_Dyn;

typedef struct elf64_dyn {
	Elf64_Sxword d_tag;
	union {
		Elf64_Xword d_val;
		Elf64_Addr d_ptr;
	} d_un;
} Elf64_Dyn;

#define ELF32_R_SYM(x)	((x) >> 8)
#define ELF32_R_TYPE(x) ((x) & 0xff)

#define ELF64_R_SYM(x)	((x) >> 32)
#define ELF64_R_TYPE(x) ((x) & 0xffffffff)

typedef struct elf32_rel {
	Elf32_Addr r_offset;
	Elf32_Word r_info;
} Elf32_Rel;

typedef struct elf32_rela {
	Elf32_Addr r_offset;
	Elf32_Word r_info;
	Elf32_Sword r_addend;
} Elf32_Rela;

typedef struct elf64_rel {
	Elf64_Addr r_offset;
	Elf64_Xword r_info;
} Elf64_Rel;

typedef struct elf64_rela {
	Elf64_Addr r_offset;
	Elf64_Xword r_info;
	Elf64_Sxword r_addend;
} Elf64_Rela;

typedef struct elf32_sym {
	Elf32_Word st_name;
	Elf32_Addr st_value;
	Elf32_Word st_size;
	unsigned char st_info;
	unsigned char st_other;
	Elf32_Half st_shndx;
} Elf32_Sym;

typedef struct elf64_sym {
	Elf64_Word st_name;
	unsigned char st_info;
	unsigned char st_other;
	Elf64_Half st_shndx;
	Elf64_Addr st_value;
	Elf64_Xword st_size;
} Elf64_Sym;

typedef struct elf32_hdr {
	unsigned char e_ident[EI_NIDENT];
	Elf32_Half e_type;
	Elf32_Half e_machine;
	Elf32_Word e_version;
	Elf32_Addr e_entry;
	Elf32_Off e_phoff;
	Elf32_Off e_shoff;
	Elf32_Word e_flags;
	Elf32_Half e_ehsize;
	Elf32_Half e_phentsize;
	Elf32_Half e_phnum;
	Elf32_Half e_shentsize;
	Elf32_Half e_shnum;
	Elf32_Half e_shstrndx;
} Elf32_Ehdr;

typedef struct elf64_hdr {
	unsigned char e_ident[EI_NIDENT];
	Elf64_Half e_type;
	Elf64_Half e_machine;
	Elf64_Word e_version;
	Elf64_Addr e_entry;
	Elf64_Off e_phoff;
	Elf64_Off e_shoff;
	Elf64_Word e_flags;
	Elf64_Half e_ehsize;
	Elf64_Half e_phentsize;
	Elf64_Half e_phnum;
	Elf64_Half e_shentsize;
	Elf64_Half e_shnum;
	Elf64_Half e_shstrndx;
} Elf64_Ehdr;

typedef struct elf32_phdr {
	Elf32_Word p_type;
	Elf32_Off p_offset;
	Elf32_Addr p_vaddr;
	Elf32_Addr p_paddr;
	Elf32_Word p_filesz;
	Elf32_Word p_memsz;
	Elf32_Word p_flags;
	Elf32_Word p_align;
} Elf32_Phdr;

typedef struct elf64_phdr {
	Elf64_Word p_type;
	Elf64_Word p_flags;
	Elf64_Off p_offset;
	Elf64_Addr p_vaddr;
	Elf64_Addr p_paddr;
	Elf64_Xword p_filesz;
	Elf64_Xword p_memsz;
	Elf64_Xword p_align;
} Elf64_Phdr;

typedef struct elf32_shdr {
	Elf32_Word sh_name;
	Elf32_Word sh_type;
	Elf32_Word sh_flags;
	Elf32_Addr sh_addr;
	Elf32_Off sh_offset;
	Elf32_Word sh_size;
	Elf32_Word sh_link;
	Elf32_Word sh_info;
	Elf32_Word sh_addralign;
	Elf32_Word sh_entsize;
} Elf32_Shdr;

typedef struct elf64_shdr {
	Elf64_Word sh_name;
	Elf64_Word sh_type;
	Elf64_Xword sh_flags;
	Elf64_Addr sh_addr;
	Elf64_Off sh_offset;
	Elf64_Xword sh_size;
	Elf64_Word sh_link;
	Elf64_Word sh_info;
	Elf64_Xword sh_addralign;
	Elf64_Xword sh_entsize;
} Elf64_Shdr;

typedef struct elf32_note {
	Elf32_Word n_namesz;
	Elf32_Word n_descsz;
	Elf32_Word n_type;
} Elf32_Nhdr;

typedef struct elf64_note {
	Elf64_Word n_namesz;
	Elf64_Word n_descsz;
	Elf64_Word n_type;
} Elf64_Nhdr;

typedef struct {
	uint32_t a_type;
	union {
		uint32_t a_val;
	} a_un;
} Elf32_auxv_t;

typedef struct {
	uint64_t a_type;
	union {
		uint64_t a_val;
	} a_un;
} Elf64_auxv_t;

#endif
