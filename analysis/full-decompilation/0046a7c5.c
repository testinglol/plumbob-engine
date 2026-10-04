
void __thiscall FUN_0046a7c5(int *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  bool bVar8;
  int local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_24 [4];
  undefined4 local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  *param_1 = param_2;
  param_1[1] = *(int *)(param_2 + 4);
  param_1[2] = *(int *)(param_2 + 8);
  FUN_00469bd0();
  local_24[0] = *(int *)(*param_1 + 0xc);
  local_24[1] = *(int *)(*param_1 + 0x10);
  local_14 = 0;
  local_24[2] = local_24[0] + 1;
  local_24[3] = local_24[1] + 1;
  FUN_00469c16(local_24);
  FUN_0046ad0a(local_24);
  local_40 = 0;
  local_50 = -1;
  local_48 = 0xffffffff;
  local_44 = 0xffffffff;
  local_4c = (param_1[4] - param_1[3]) / 0x14 + -1;
  FUN_0046ad3a(&local_50);
  local_6c = 0;
  local_7c = -1;
  local_78 = -1;
  local_74 = 0xffffffff;
  local_70 = 0xffffffff;
  FUN_0046ad3a(&local_7c);
  puVar3 = *(undefined4 **)*param_1;
  piVar5 = (int *)*puVar3;
  do {
    if (piVar5 == (int *)puVar3[1]) {
      return;
    }
    local_8 = -1;
    FUN_0040555d(&local_8);
    local_c = (int *)(param_1[7] + -4);
    local_8 = -1;
    FUN_0040555d(&local_8);
    local_10 = (int *)(param_1[10] + -4);
    local_8 = FUN_004697dd(piVar5);
    if ((local_8 == 0) || (*(int *)(local_8 + 0x10) != 0x7fffffff)) {
      iVar4 = FUN_00469792(piVar5);
      iVar1 = local_8;
      if (iVar4 == -1) {
        bVar8 = local_8 == 0;
        piVar6 = piVar5;
        piVar7 = local_24;
        for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar7 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar7 = piVar7 + 1;
        }
        if (bVar8) {
          local_14 = 0;
        }
        else {
          local_14 = *(undefined4 *)(iVar1 + 0x10);
        }
        cVar2 = FUN_00469c16(local_24);
        if (cVar2 == '\0') goto LAB_0046a9bb;
        FUN_0046ad0a(local_24);
        iVar4 = (param_1[4] - param_1[3]) / 0x14 + -1;
      }
      local_6c = *(undefined4 *)(param_1[3] + 0x10 + iVar4 * 0x14);
      local_74 = 0xffffffff;
      local_70 = 0xffffffff;
      local_7c = ((int)piVar5 - **(int **)*param_1) / 0x14;
      piVar6 = param_1 + 0xf;
      local_78 = iVar4;
      FUN_0046ad3a(&local_7c);
      *local_c = (param_1[0x10] - *piVar6) / 0x2c + -1;
      local_4c = *(int *)(*piVar6 + 4);
      local_48 = 0xffffffff;
      local_44 = 0xffffffff;
      local_50 = ((int)piVar5 - **(int **)*param_1) / 0x14;
      local_40 = piVar5[4];
      FUN_0046ad3a(&local_50);
      *local_10 = (param_1[0x10] - *piVar6) / 0x2c + -1;
    }
LAB_0046a9bb:
    piVar5 = piVar5 + 5;
    puVar3 = *(undefined4 **)*param_1;
  } while( true );
}

