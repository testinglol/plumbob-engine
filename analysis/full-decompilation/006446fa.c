
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006446fa(void)

{
  void *pvVar1;
  char *pcVar2;
  int local_c;
  int local_8;
  
  if (DAT_00705350 == 0) {
    FUN_0063ccc0();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_00703c50,0x104);
  _DAT_00703ae0 = &DAT_00703c50;
  pcVar2 = &DAT_00703c50;
  if (*DAT_00705348 != '\0') {
    pcVar2 = DAT_00705348;
  }
  FUN_00644793(pcVar2,0,0,&local_8,&local_c);
  pvVar1 = _malloc(local_c + local_8 * 4);
  if (pvVar1 == (void *)0x0) {
    __amsg_exit(8);
  }
  FUN_00644793(pcVar2,pvVar1,(void *)((int)pvVar1 + local_8 * 4),&local_8,&local_c);
  _DAT_00703ac8 = pvVar1;
  _DAT_00703ac4 = local_8 + -1;
  return;
}

