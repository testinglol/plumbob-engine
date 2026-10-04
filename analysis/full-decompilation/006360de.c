
uint FUN_006360de(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  piVar1 = param_4;
  uVar5 = param_2 * param_3;
  if (uVar5 == 0) {
    param_3 = 0;
  }
  else {
    uVar4 = uVar5;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((piVar1[3] & 0x108U) == 0) || (uVar6 = piVar1[1], uVar6 == 0)) {
        if (param_4 <= uVar4) {
          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = FUN_0063734b(piVar1), iVar2 != 0)) {
LAB_006361df:
            return (uVar5 - uVar4) / param_2;
          }
          uVar6 = uVar4;
          if (param_4 != (int *)0x0) {
            uVar6 = uVar4 - uVar4 % (uint)param_4;
          }
          uVar3 = FUN_0063d061(piVar1[4],param_1,uVar6);
          if ((uVar3 == 0xffffffff) || (uVar4 = uVar4 - uVar3, uVar3 < uVar6)) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_006361df;
          }
          goto LAB_00636196;
        }
        iVar2 = FUN_006411ee((int)*param_1,piVar1);
        if (iVar2 == -1) goto LAB_006361df;
        param_1 = param_1 + 1;
        param_4 = (int *)piVar1[6];
        uVar4 = uVar4 - 1;
        if ((int)param_4 < 1) {
          param_4 = (int *)0x1;
        }
      }
      else {
        uVar3 = uVar4;
        if (uVar6 <= uVar4) {
          uVar3 = uVar6;
        }
        FUN_00636510(*piVar1,param_1,uVar3);
        piVar1[1] = piVar1[1] - uVar3;
        *piVar1 = *piVar1 + uVar3;
        uVar4 = uVar4 - uVar3;
LAB_00636196:
        param_1 = param_1 + uVar3;
      }
    } while (uVar4 != 0);
  }
  return param_3;
}

