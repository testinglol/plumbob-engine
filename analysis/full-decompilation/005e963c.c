
undefined1 __fastcall FUN_005e963c(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    uVar2 = FUN_005dbf32();
    return uVar2;
  }
  cVar1 = FUN_005dbf32();
  if (cVar1 == '\0') {
    return 0;
  }
  uVar3 = FUN_005e749a(0);
  FUN_005dde6d(uVar3);
  return 1;
}

