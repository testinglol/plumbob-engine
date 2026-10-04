
undefined1 __fastcall FUN_005351d0(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    uVar2 = FUN_005dbf32();
    return uVar2;
  }
  cVar1 = FUN_005dbf32();
  return cVar1 != '\0';
}

