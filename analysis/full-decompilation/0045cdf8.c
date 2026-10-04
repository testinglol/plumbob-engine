
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char __thiscall FUN_0045cdf8(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  char cVar4;
  int *piVar5;
  undefined2 extraout_var;
  int iVar6;
  float10 fVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  char local_408 [1024];
  float local_8;
  
  cVar3 = FUN_00452237(param_2);
  if ((((*(short *)((int)param_1 + 0x8e) == 0) && (param_2 % 10 == 0)) &&
      (local_8 = (float)(int)*(short *)((int)param_1 + 0x636) * _DAT_00667420,
      (float)_DAT_00667418 < local_8)) && (local_8 < (float)_DAT_00667410)) {
    piVar5 = (int *)(**(code **)(*param_1 + 0x8c))();
    pfVar10 = &local_8;
    pfVar9 = &local_8;
    pfVar8 = &local_8;
    (**(code **)(*piVar5 + 0xac))(pfVar8,pfVar9,pfVar10);
    FUN_005a07ba(pfVar8,pfVar9,pfVar10);
  }
  if (cVar3 != '\0') {
    if (param_1[0x204] + 0x3c <= param_2) {
      param_1[0x204] = param_2;
      FUN_0045d2b1();
    }
    (**(code **)(*(int *)param_1[0x2b7] + 0x50))(DAT_006e4870 == '\0');
    FUN_0045e5a9();
    if ((short)param_1[0x2bf] != -5) {
      fVar7 = (float10)FUN_0045d060(CONCAT22(extraout_var,(short)param_1[0x2bf]));
      local_8 = (float)fVar7;
      if ((((short)param_1[0x2bf] == 0) && (cVar4 = FUN_004074bc(), cVar4 == '\0')) &&
         (local_8 < _DAT_0066657c)) {
        local_8 = 0.0;
      }
      param_1[0x1f0] = (int)local_8;
    }
    *(short *)((int)param_1 + 0x5c2) = *(short *)((int)param_1 + 0x5c2) + 1;
    for (piVar5 = (int *)param_1[0x2b4]; piVar5 != (int *)param_1[0x2b5]; piVar5 = piVar5 + 3) {
      fVar1 = (float)piVar5[2];
      pfVar10 = (float *)(param_1 + *piVar5 + 0x1e3);
      local_8 = (float)piVar5[1];
      if (_DAT_0066657c <= local_8) {
        if ((*pfVar10 < fVar1) &&
           (fVar2 = *pfVar10, *pfVar10 = local_8 + fVar2, fVar1 < local_8 + fVar2))
        goto LAB_0045cf75;
      }
      else if ((fVar1 < *pfVar10) &&
              (fVar2 = *pfVar10, *pfVar10 = local_8 + fVar2, local_8 + fVar2 < fVar1)) {
LAB_0045cf75:
        *pfVar10 = fVar1;
      }
    }
    if ((((param_2 % 10 == 0) && ((short)param_1[0x173] == 0)) &&
        (*(short *)((int)param_1 + 0x8e) == 0)) && (_DAT_0066657c <= (float)param_1[0x1ee])) {
      iVar6 = FUN_0045c4b5();
      local_8 = (float)CONCAT31(local_8._1_3_,iVar6 != 0);
      FUN_004165d9(local_8);
    }
    if (*(short *)((int)param_1 + 0x58e) != 0) {
      FUN_004a6bc2(param_1,(int)*(short *)((int)param_1 + 0x58e));
      *(undefined2 *)((int)param_1 + 0x58e) = 0;
    }
    if (*(char *)(DAT_006e486c + 0x5a) != '\0') {
      (**(code **)(*(int *)param_1[0x2b7] + 0xa8))(local_408);
      iVar6 = _strcmp(local_408,(char *)(param_1 + 99));
      if (iVar6 != 0) {
        FUN_004a6ba5(param_1,local_408);
        FUN_006358b0(param_1 + 99,local_408);
      }
    }
    if (DAT_006e5438 != '\0') {
      FUN_0046c04e(param_1);
    }
  }
  return cVar3;
}

