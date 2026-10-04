
void __fastcall FUN_005d5c22(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  
  iVar2 = (**(code **)*param_1)();
  piVar6 = (int *)(-(uint)(iVar2 != 0) & iVar2 - 0x48U);
  iVar2 = (**(code **)(*param_1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x1c))();
  piVar4 = (int *)(**(code **)(*param_1 + 0x38))();
  (**(code **)(*piVar4 + 4))(-(uint)(iVar2 != 0) & iVar2 - 0x48U);
  piVar4 = (int *)(**(code **)(*param_1 + 0x38))();
  (**(code **)(*piVar4 + 4))(piVar6);
  piVar4 = (int *)(**(code **)(*param_1 + 0x38))();
  iVar2 = *piVar4;
  uVar5 = (**(code **)(*piVar6 + 0x18))();
  (**(code **)(iVar2 + 8))(uVar5);
  cVar1 = (**(code **)(*piVar6 + 0x14))();
  if (cVar1 == '\0') {
    if ((char)param_1[0x4f] != '\0') {
      (**(code **)(param_1[5] + 4))(-(uint)(param_1[0x4e] != 0) & param_1[0x4e] + 4U);
    }
    (**(code **)(param_1[5] + 4))(-(uint)(iVar3 != 0) & iVar3 - 0x48U);
  }
  (**(code **)(param_1[0x50] + 8))();
  piVar4 = (int *)(**(code **)(*param_1 + 0x38))();
  cVar1 = (**(code **)(*piVar4 + 0xc))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x28))(0xffffffff);
  }
  return;
}

