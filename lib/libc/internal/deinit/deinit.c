extern void __libc_deinit_tls();

void __libc_deinit(void)
{
	__libc_deinit_tls();
}
