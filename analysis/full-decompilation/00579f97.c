
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00579f97(int param_1)

{
  int iVar1;
  int iVar2;
  double dVar3;
  uint uVar4;
  float10 fVar5;
  double local_10;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    return;
  }
  if (DAT_006f642d != '\0') {
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x1d) = 1;
  }
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(iVar1 + 0x14);
  local_10 = (double)((float10)(iVar2 + -0x200) * (float10)_DAT_00671748);
  fVar5 = (float10)(*(int *)(iVar1 + 0x18) + -0x200) * (float10)_DAT_00671748;
  if (*(char *)(iVar1 + 0x1d) != '\0') {
    if ((iVar2 == 0x200) && (*(int *)(iVar1 + 0x18) == 0x200)) {
      uVar4 = _rand();
      uVar4 = uVar4 & 3;
      if (DAT_006f642c != '\0') {
        uVar4 = DAT_006f6430;
      }
      if (uVar4 == 0) {
        local_10 = 0.0;
        fVar5 = (float10)1;
      }
      else if (uVar4 == 1) {
        local_10 = 0.0;
        fVar5 = (float10)_DAT_00671740;
      }
      else {
        dVar3 = _DAT_00671740;
        if (uVar4 != 2) {
          if (uVar4 != 3) {
            fVar5 = (float10)(double)fVar5;
            goto LAB_0057a096;
          }
          dVar3 = 1.0;
        }
        local_10 = dVar3;
        fVar5 = (float10)0;
      }
      goto LAB_0057a096;
    }
    if ((*(char *)(iVar1 + 0x1d) != '\0') && (iVar2 == 0x200)) {
      uVar4 = _rand();
      local_10 = (double)(int)((uVar4 & 1) * 2 + -1);
      fVar5 = (float10)(double)fVar5;
    }
  }
  if ((*(char *)(*(int *)(param_1 + 0xc) + 0x1d) != '\0') &&
     (*(int *)(*(int *)(param_1 + 0xc) + 0x18) == 0x200)) {
    uVar4 = _rand();
    fVar5 = (float10)(int)((uVar4 & 1) * 2 + -1);
  }
LAB_0057a096:
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 4) + 0xd0))
              ((float)((float10)_DAT_006cf1f8 * (float10)local_10),0,
               (float)((float10)_DAT_006cf1f8 * fVar5));
  }
  return;
}

