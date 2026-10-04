
undefined1 __fastcall FUN_004ff964(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *local_c;
  int *local_8;
  
  local_c = param_1;
  local_8 = param_1;
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 == '\0') {
    local_8 = (int *)0x0;
    local_c = (int *)0x280;
    FUN_004ffa2d(&local_c);
    (**(code **)(*param_1 + 0x90))(0x10,0);
    iVar3 = FUN_005dd5e1(0x28,0x28,0x28);
    param_1[0x19] = iVar3;
    uVar4 = FUN_005e74ca(0);
    FUN_005dde6d(uVar4);
    cVar1 = FUN_005dbf32();
    uVar2 = cVar1 != '\0';
  }
  else {
    uVar2 = FUN_005dbf32();
  }
  return uVar2;
}

