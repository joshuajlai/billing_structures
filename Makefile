COMPOSER=~/.bin/composer/composer.phar

install: install_composer
	php ${COMPOSER} install --no-autoloader
.PHONY: install

update: install_composer
	php ${COMPOSER} update --no-autoloader
.PHONY: update

install_composer:
	test -f $(COMPOSER) || mkdir -p `dirname $(COMPOSER)`
	test -f $(COMPOSER) || wget -O $(COMPOSER) https://getcomposer.org/download/1.9.2/composer.phar
.PHONY: composer-fetch

check:
	hh_client
.PHONY: check

update_autoload:
	./vendor/bin/hh-autoload
.PHONY: update_autoload

test: update_autoload check
	 hhvm vendor/bin/hacktest tests/
.PHONY: test

