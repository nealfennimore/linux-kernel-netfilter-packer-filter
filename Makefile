HOOK_MAKEFILE = build/Makefile

default:
	$(MAKE) -f $(HOOK_MAKEFILE)
%:
	$(MAKE) -f $(HOOK_MAKEFILE) $@