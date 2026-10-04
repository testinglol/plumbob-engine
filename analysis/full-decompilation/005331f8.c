
undefined1 __fastcall FUN_005331f8(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    uVar2 = FUN_005dbf32();
    return uVar2;
  }
  cVar1 = FUN_005dbf32();
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(*param_1 + 0x174))(1,0);
  *(undefined1 *)(param_1 + 0x1b) = 1;
  param_1[0x39] = DAT_006f2a94;
  (**(code **)(*param_1 + 0x60))(param_1[0x1f],param_1[0x20],param_1[0x21],param_1[0x22]);
  return 1;
}

