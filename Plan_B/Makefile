

URL=http://iui.googlecode.com/files/iui-0.4.zip
ZIP=iui-0.4.zip
FOLDER=iui-0.4
INSTALL_FOLDER=iui

all: $(INSTALL_FOLDER)

$(INSTALL_FOLDER): $(FOLDER)
	mkdir -p $(INSTALL_FOLDER)
	cp -vR $(FOLDER)/web-app/iui/* ./$(INSTALL_FOLDER)
	touch $(INSTALL_FOLDER)

$(FOLDER): $(ZIP)
	unzip "$(ZIP)"
	touch $(FOLDER)

$(ZIP):
	curl -o "$(ZIP)" "$(URL)"

test: $(INSTALL_FOLDER)
	mkdir -p $(HOME)/Sites/tricorder
	cp -vR $(INSTALL_FOLDER) index.html *.js *.map images $(HOME)/Sites/tricorder

.PHONY: clean
clean:
	rm -rf $(FOLDER) $(INSTAL_FOLDER)

.PHONY: distclean
distclean: clean
	rm -f $(ZIP)

