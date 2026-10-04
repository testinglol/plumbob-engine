
void FUN_00401b39(size_t param_1)

{
  void *pvVar1;
  undefined1 local_10 [12];
  
  do {
    if (DAT_006de5ac == (code *)0x0) {
      FUN_00401b76(s_bad_allocation_006c099c);
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_10,&DAT_00693038);
    }
    (*DAT_006de5ac)();
    pvVar1 = _malloc(param_1);
  } while (pvVar1 == (void *)0x0);
  return;
}

