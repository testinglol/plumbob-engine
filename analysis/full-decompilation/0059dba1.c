
undefined4 FUN_0059dba1(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = (char *)FUN_004705f2((short)param_2 + 1,0xffffffff);
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    uVar2 = FUN_0059dabd(param_1,pcVar1);
    return uVar2;
  }
  FUN_004f6d73(param_1,&DAT_006c5288,param_2);
  return 0;
}

