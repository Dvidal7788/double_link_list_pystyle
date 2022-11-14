.PHONY: printvars
printvars:
    @$(foreach V,$(sort $(.VARIABLES)), $(if $(filter-out environment% default automatic, $(origin $V)),$(warning $V=$($V) ($(value $V)))))

# Terminal cmd to print variables:
# gmake -f Makefile -f helper.mak printvars