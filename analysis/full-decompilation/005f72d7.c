
undefined1 __fastcall FUN_005f72d7(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    uVar2 = thunk_FUN_005dbf32();
    return uVar2;
  }
  cVar1 = thunk_FUN_005dbf32();
  return cVar1 != '\0';
}

