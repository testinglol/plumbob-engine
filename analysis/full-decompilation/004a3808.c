
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004a3808(int *param_1,double param_2,double param_3,undefined4 param_4,char param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  int iVar5;
  void *pvVar6;
  float *pfVar7;
  int iVar8;
  float10 fVar9;
  float10 fVar10;
  
  FUN_00634ecc();
  *param_1 = 0;
  param_1[1] = 0;
  dVar4 = param_2 * param_2 - param_3 * param_3;
  param_1[2] = 0x80 >> (3U - (char)param_4 & 0x1f);
  fVar9 = (float10)FUN_00636264(dVar4);
  fVar10 = (float10)FUN_00636264(_DAT_00668308);
  FUN_00636ac8((double)((float10)(double)fVar9 / (fVar10 * (float10)_DAT_006682f8)));
  iVar5 = __ftol();
  iVar5 = (iVar5 + 1) * param_1[2];
  param_1[1] = iVar5;
  iVar8 = iVar5 / 2;
  if (param_5 == '\0') {
    pvVar6 = _malloc(iVar8 * iVar5);
    *param_1 = (int)pvVar6;
    if (pvVar6 == (void *)0x0) {
      param_1[1] = 0;
      return 1;
    }
    fVar9 = (float10)FUN_004a39a0(iVar8,iVar8 / 2,iVar5,iVar8,param_4);
    fVar9 = (float10)FUN_00636264((double)(fVar9 * fVar9 + (float10)(param_3 * param_3)));
    fVar10 = (float10)FUN_00636264(dVar4);
    FUN_0049c12a((float)fVar9,(float)fVar10);
    pfVar7 = operator_new(0x1000);
    if ((pfVar7 != (float *)0x0) && (_param_5 = 0, 0 < iVar8)) {
      do {
        iVar2 = param_1[1];
        iVar1 = 0;
        iVar3 = *param_1;
        param_2._4_4_ = pfVar7;
        if (0 < iVar5) {
          do {
            FUN_004a39a0(iVar1,_param_5,iVar5,iVar8,param_4);
            fVar9 = (float10)FUN_00636264();
            iVar1 = iVar1 + 1;
            *param_2._4_4_ = (float)fVar9;
            param_2._4_4_ = param_2._4_4_ + 1;
          } while (iVar1 < iVar5);
        }
        FUN_0049c15e(iVar2 * _param_5 + iVar3,pfVar7,iVar5);
        _param_5 = _param_5 + 1;
      } while (_param_5 < iVar8);
    }
    FUN_006321f0();
  }
  return 0;
}

