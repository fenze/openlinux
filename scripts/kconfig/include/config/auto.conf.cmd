autoconfig := include/config/auto.conf

deps_config := \
	/Users/fenze/Developer/openlinux/ref/Kconfig \

$(autoconfig): $(deps_config)
$(deps_config): ;
