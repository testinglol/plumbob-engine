
void __thiscall FUN_0046bdc6(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  if (param_3 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(param_3 + 8);
  }
  uVar1 = 0;
  uVar3 = 0;
  uVar5 = 0xffffffff;
  if (iVar4 != 0) {
    FUN_004573f9();
    uVar1 = FUN_0045741b();
    uVar3 = *(undefined2 *)(iVar4 + 0xf0);
    uVar5 = *(undefined4 *)(param_3 + 0x10);
  }
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined2 *)(param_1 + 0xc) = uVar3;
  *(undefined4 *)(param_1 + 0x10) = uVar5;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  puVar2 = (undefined4 *)FUN_0046b95f(param_2);
  puVar6 = (undefined4 *)(param_1 + 0x14);
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar6 = puVar6 + 1;
  }
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(*(int *)(DAT_006e486c + 0x1c) + 0x98);
  return;
}

