
void __thiscall FUN_004614cd(int *param_1,float *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  
  iVar4 = param_1[2];
  if (iVar4 != param_1[3]) {
    iVar3 = 0;
    if (0 < iVar4) {
      pfVar5 = (float *)*param_1;
      iVar3 = 0;
      do {
        if (*pfVar5 == *param_2) {
          return;
        }
        if (*param_2 < *pfVar5) break;
        iVar3 = iVar3 + 1;
        pfVar5 = pfVar5 + 2;
      } while (iVar3 < iVar4);
    }
    param_1[2] = iVar4 + 1;
    if (iVar3 + 1 <= iVar4) {
      do {
        iVar2 = iVar4 * 8;
        puVar1 = (undefined4 *)(*param_1 + iVar4 * 8);
        iVar4 = iVar4 + -1;
        *puVar1 = *(undefined4 *)(*param_1 + -8 + iVar2);
        puVar1[1] = puVar1[-1];
      } while (iVar3 + 1 <= iVar4);
    }
    iVar4 = *param_1;
    *(float *)(iVar4 + iVar3 * 8) = *param_2;
    *(float *)(iVar4 + 4 + iVar3 * 8) = param_2[1];
    FUN_0046154c();
  }
  return;
}

