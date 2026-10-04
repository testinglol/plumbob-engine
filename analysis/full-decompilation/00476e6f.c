
void __thiscall FUN_00476e6f(int *param_1,int param_2)

{
  undefined4 uVar1;
  short sVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 local_14 [4];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (((*(byte *)(param_2 + 0x11) & 8) == 0) && (DAT_006e54ac != (int *)0x0)) {
    local_c = 0;
    local_8 = (**(code **)(*param_1 + 0x38))();
    if (local_8 == 0) {
      local_8 = 1;
    }
    puVar5 = (undefined4 *)(param_2 + 0xc);
    (**(code **)(*DAT_006e54ac + 0x44))(puVar5);
    puVar3 = (undefined4 *)(**(code **)(*param_1 + 4))(local_14,*puVar5,1);
    uVar1 = *puVar3;
    local_10 = puVar3[1];
    sVar2 = (**(code **)(*DAT_006e54ac + 0x10))();
    if (sVar2 != 0) {
      local_c = (**(code **)(*param_1 + 0x28))(*puVar5,local_8,1);
    }
    (**(code **)(*DAT_006e54ac + 0x2c))(uVar1,local_10,local_c,param_2);
    iVar4 = FUN_00492d2c();
    if (iVar4 != 0) {
      FUN_00492c68();
      FUN_00492bc4();
    }
  }
  return;
}

