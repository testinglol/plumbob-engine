
undefined4 __thiscall FUN_0048deb1(int param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  SHORT SVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 local_10;
  undefined4 local_c;
  char local_5;
  
  SVar3 = GetKeyState(0x10);
  local_5 = SVar3 < 0;
  iVar4 = (**(code **)(*param_2 + 0x1b0))();
  uVar6 = iVar4 + *(int *)(param_1 + 100);
  if (((int)uVar6 < 0) ||
     (piVar1 = *(int **)(param_1 + 0x58), (uint)((piVar1[1] - *piVar1) / 0x28) <= uVar6)) {
LAB_0048df80:
    if (local_5 == '\0') {
      (**(code **)(*param_2 + 0x26c))();
    }
    FUN_00492c37();
    uVar5 = 0;
  }
  else {
    if (*(char *)(*piVar1 + 0x14 + uVar6 * 0x28) == '\0') {
      iVar4 = *(int *)(*piVar1 + uVar6 * 0x28 + 0x24);
      if ((*(int *)(iVar4 + 4) == 0) || (cVar2 = FUN_0045d377(iVar4), cVar2 == '\0'))
      goto LAB_0048df80;
      puVar8 = &local_c;
      puVar7 = &local_10;
      (**(code **)(*DAT_006fe8bc + 0x18))(puVar7,puVar8);
      FUN_005d9928(puVar7,puVar8);
      uVar5 = FUN_0045741b();
      uVar5 = FUN_004e988f(uVar5);
      FUN_004d2e56(*(undefined4 *)(iVar4 + 0x3c),uVar5,local_10,local_c);
      if (local_5 == '\0') goto LAB_0048df6e;
      FUN_00587cea();
    }
    else {
LAB_0048df6e:
      (**(code **)(*param_2 + 0x26c))();
    }
    uVar5 = 1;
  }
  return uVar5;
}

