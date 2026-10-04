
void __fastcall FUN_0052b1e7(int *param_1)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char cVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  if ((param_1[0x3e] != 0) && (param_1[0x3d] != 0)) {
    iVar4 = FUN_004ed9f9();
    uVar9 = 1;
    uVar8 = 0;
    if (iVar4 == 0) {
      FUN_005f436c(&DAT_006de560,0,1);
    }
    else {
      uVar5 = FUN_004ed9f9();
      FUN_005f436c(uVar5,uVar8,uVar9);
      FUN_005f48ed();
    }
    iVar4 = FUN_004eda2e();
    if (iVar4 != 0) {
      iVar4 = *(int *)param_1[0x3f];
      uVar8 = FUN_004eda2e();
      (**(code **)(iVar4 + 0x1a0))(uVar8);
    }
    iVar4 = FUN_004ed868();
    iVar6 = FUN_004ed827();
    if ((iVar4 == 0) || (iVar6 == 0)) {
      cVar7 = '\0';
    }
    else {
      cVar7 = '\x01';
    }
    piVar1 = (int *)param_1[0x38];
    if ((char)piVar1[0x5a] != cVar7) {
      *(char *)(piVar1 + 0x5a) = cVar7;
      (**(code **)(*piVar1 + 0x168))();
    }
    if ((iVar4 == 0) || (iVar6 == 0)) {
      cVar7 = '\0';
    }
    else {
      cVar7 = '\x01';
    }
    piVar1 = (int *)param_1[0x3a];
    if ((char)piVar1[0x5a] != cVar7) {
      *(char *)(piVar1 + 0x5a) = cVar7;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar2 = (int *)param_1[0x39];
    piVar1 = piVar2 + 0x5a;
    bVar3 = iVar4 < iVar6 + -1;
    if ((bool)(char)*piVar1 != bVar3) {
      *(bool *)piVar1 = bVar3;
      (**(code **)(*piVar2 + 0x168))();
    }
    piVar1 = (int *)param_1[0x3b];
    if ((bool)(char)piVar1[0x5a] != bVar3) {
      *(bool *)(piVar1 + 0x5a) = bVar3;
      (**(code **)(*piVar1 + 0x168))();
    }
    piVar2 = (int *)param_1[0x37];
    piVar1 = piVar2 + 0x5a;
    if ((bool)(char)*piVar1 != 0 < iVar6) {
      *(bool *)piVar1 = 0 < iVar6;
      (**(code **)(*piVar2 + 0x168))();
    }
    iVar4 = FUN_004ed827();
    if (iVar4 == 0) {
      (**(code **)(*(int *)param_1[0x3e] + 0x98))();
    }
  }
  (**(code **)(*param_1 + 0x168))();
  return;
}

