
void __thiscall FUN_00423e3b(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int local_8;
  
  iVar1 = param_2;
  local_8 = param_1;
  if (0x48 < param_3) {
    param_2 = 10;
    FUN_00464a5e(&param_2,1);
  }
  if (param_3 < 0x48) {
    if (0x1e < param_3) {
      param_2 = 4;
      goto LAB_00423e6e;
    }
    param_2 = 0;
  }
  else {
    param_2 = 9;
LAB_00423e6e:
    FUN_00464a5e(&param_2,1);
  }
  if (1 < param_2) {
    FUN_00464d2c(param_1 + 0x28);
    FUN_00464a4e(param_1 + 0x1c,1);
  }
  if (param_2 < 1) goto LAB_00423efe;
  FUN_00464a4e((int *)(param_1 + 0x18),1);
  if (*(int *)(param_1 + 0x18) == 0) goto LAB_00423efe;
  if (param_2 < 8) {
    if (2 < param_2) {
      uVar4 = 0x50;
      goto LAB_00423edb;
    }
    FUN_00464973(param_1 + 0x74,0x40);
    local_8 = 0;
    uVar4 = 1;
    piVar2 = &local_8;
  }
  else {
    uVar4 = 0x100;
LAB_00423edb:
    piVar2 = (int *)(param_1 + 0x74);
  }
  FUN_00464973(piVar2,uVar4);
LAB_00423efe:
  FUN_00464973(param_1,1);
  FUN_00464a5e((undefined4 *)(param_1 + 4),1);
  if (*(int *)(iVar1 + 0xc) == 0) {
    uVar4 = FUN_0043acf5(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 8) = uVar4;
  }
  if ((param_2 < 2) && (*(int *)(param_1 + 8) != 0)) {
    iVar3 = (*(code *)**(undefined4 **)(param_1 + 0x28))();
    if (iVar3 == 0) {
      FUN_00457f7a(param_1 + 0x28);
    }
  }
  FUN_004651dc(iVar1,param_3);
  return;
}

