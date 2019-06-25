.PHONY: install test check update_autoload

install:
	hhvm ~/Workspace/bin/composer.phar install

check:
	hh_client

update_autoload:
	./vendor/bin/hh-autoload

test: update_autoload check
	 hhvm vendor/bin/hacktest tests/

