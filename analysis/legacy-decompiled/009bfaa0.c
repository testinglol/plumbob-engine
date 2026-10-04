
char __thiscall FUN_009bfaa0(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  char cVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_009bf6e0(0);
  pcVar1 = param_1 + 8;
  cVar2 = FUN_009cc710(param_2,param_3,param_4);
  if (cVar2 != '\0') {
    cVar2 = FUN_009cec50(pcVar1);
    if (cVar2 != '\0') {
      cVar2 = FUN_009c97f0(pcVar1);
      if (cVar2 != '\0') {
        cVar2 = FUN_009bfba0();
        if (cVar2 != '\0') {
          local_c = 1;
          local_8 = 1;
          cVar2 = FUN_009ce4a0(pcVar1,*(undefined4 *)(*(int *)(param_1 + 0x78) + 8),
                               *(undefined4 *)(*(int *)(param_1 + 0x78) + 0xc),0x1000,&local_c,1);
          if (cVar2 != '\0') {
            *param_1 = '\x01';
            FUN_009bf3a0(param_3,param_4);
            goto LAB_009bfb37;
          }
        }
      }
    }
  }
  *param_1 = '\0';
LAB_009bfb37:
  cVar2 = *param_1;
  if (cVar2 == '\0') {
    FUN_009bf6e0(1);
  }
  return cVar2;
}

