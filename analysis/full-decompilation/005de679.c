
undefined1 __fastcall FUN_005de679(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 0x8c))(1);
  if (cVar1 == '\0') {
    return 0;
  }
  cVar1 = (**(code **)(*param_1 + 0x8c))(8);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*param_1 + 0x8c))(0x8000);
    if (cVar1 != '\0') goto LAB_005de6c2;
  }
  cVar1 = (**(code **)(*param_1 + 0x8c))(0x80000);
  if (cVar1 == '\0') {
    if (param_1[0x2d] != 0) {
      FUN_00473496(DAT_006e5490);
      uVar2 = __ftol();
      return uVar2;
    }
    return 0xff;
  }
LAB_005de6c2:
  return (char)param_1[0x2c];
}

