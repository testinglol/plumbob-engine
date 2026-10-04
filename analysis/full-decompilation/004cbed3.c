
void __thiscall FUN_004cbed3(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x24) = 1;
  *(int *)(param_1 + 0x28) = param_2;
  iVar1 = *(int *)(param_2 + 0x60);
  thunk_FUN_00457ea7();
  uVar2 = FUN_004096c2();
  FUN_005d49b7(uVar2);
  FUN_0045754a();
  uVar2 = FUN_004096c2();
  FUN_005d49b7(uVar2);
  *(int *)(param_1 + 0x1c) = (int)*(short *)(iVar1 + 0x24);
  FUN_0045804b(param_1);
  if (((*(short *)(iVar1 + 0x4e) == 0) && (*(short *)(iVar1 + 0x50) == 0)) &&
     (*(short *)(iVar1 + 0x8a) == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 4;
  }
  FUN_004cc877(0,uVar2);
  return;
}

