
int FUN_0049e846(int param_1,int param_2,int *param_3,int param_4,int *param_5,char param_6)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int iVar8;
  int local_c;
  
  iVar2 = FUN_0049e977(param_3,param_4);
  param_4 = 0;
  if (0 < param_2) {
    puVar4 = (undefined2 *)(param_1 + 0xc);
    do {
      uVar3 = FUN_0049cdb0((float)param_4 / (float)param_2);
      uVar1 = FUN_004a44f7(uVar3);
      puVar6 = puVar4 + 1;
      puVar7 = puVar4 + -6;
      *puVar7 = uVar1;
      *puVar6 = uVar1;
      puVar4[-5] = uVar1;
      *puVar4 = uVar1;
      puVar4[-4] = uVar1;
      puVar4[-1] = uVar1;
      puVar4[-3] = uVar1;
      puVar4[-2] = uVar1;
      if (param_5 != (int *)0x0) {
        param_3 = param_5;
        local_c = 4;
        do {
          if (*param_3 != 0) {
            uVar3 = FUN_0049cdb0((float)(param_4 - *param_3) / (float)param_2);
            uVar1 = FUN_004a44f7(uVar3);
            *puVar7 = uVar1;
            *puVar6 = uVar1;
          }
          param_3 = param_3 + 1;
          puVar7 = puVar7 + 1;
          puVar6 = puVar6 + -1;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
      iVar2 = param_4 + 1;
      puVar4 = puVar4 + 8;
      param_4 = iVar2;
    } while (iVar2 < param_2);
  }
  if ((param_6 != '\0') && (iVar8 = 0, 0 < param_2)) {
    puVar4 = (undefined2 *)(param_1 + 2);
    do {
      iVar2 = iVar8 / 4;
      iVar5 = iVar8 % 4;
      if (0 < iVar5) {
        do {
          uVar1 = puVar4[-1];
          iVar2 = CONCAT22((short)((uint)iVar2 >> 0x10),uVar1);
          puVar4[-1] = *puVar4;
          puVar4[6] = *puVar4;
          iVar5 = iVar5 + -1;
          *puVar4 = puVar4[1];
          puVar4[5] = puVar4[1];
          puVar4[1] = puVar4[2];
          puVar4[4] = puVar4[2];
          puVar4[2] = uVar1;
          puVar4[3] = uVar1;
        } while (iVar5 != 0);
      }
      iVar8 = iVar8 + 1;
      puVar4 = puVar4 + 8;
    } while (iVar8 < param_2);
  }
  return iVar2;
}

