
undefined1 __fastcall FUN_004d55fe(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    uVar2 = FUN_005dbf32();
    return uVar2;
  }
  (**(code **)(*param_1 + 0x90))(0x10,0);
  (**(code **)(*param_1 + 0x90))(4,0);
  iVar3 = FUN_005dd5e1(0x28,0x28,0x28);
  param_1[0x19] = iVar3;
  cVar1 = FUN_005dbf32();
  return cVar1 != '\0';
}

