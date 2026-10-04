
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c9e4d(int param_1,int param_2,float *param_3,int param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  tagRECT local_1c;
  int local_c;
  int local_8;
  
  iVar2 = *(int *)(param_1 + 0x2c);
  local_1c.left = *(int *)(iVar2 + 0x68);
  local_1c.top = *(int *)(iVar2 + 0x6c);
  local_1c.right = *(LONG *)(iVar2 + 0x70);
  local_1c.bottom = *(LONG *)(iVar2 + 0x74);
  OffsetRect(&local_1c,-local_1c.left,-local_1c.top);
  local_c = param_4 + -1;
  iVar4 = 3 - *(int *)(param_1 + 0x20);
  iVar2 = *(int *)(local_8 + 0x6c + iVar4 * 4) * local_c;
  param_2 = (4 << ((byte)*(int *)(param_1 + 0x20) & 0x1f)) + iVar2 + param_2;
  fVar5 = (float10)FUN_00434e9b();
  iVar3 = local_1c.top - *(int *)(local_8 + 0x1c + iVar4 * 4);
  if ((param_2 < iVar3) || (*(int *)(local_8 + 0x28) + local_1c.top <= param_2)) {
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(int *)(param_1 + 0x24) = iVar3;
  }
  else {
    *(int *)(param_1 + 0x24) = param_2 - iVar2;
    iVar2 = *(int *)(*(int *)(local_8 + (7 - *(int *)(param_1 + 0x20)) * 4) +
                    (param_2 - DAT_006f0084) * 4);
    *(int *)(param_1 + 0x28) = iVar2;
    *(int *)(param_1 + 0x28) = *(int *)(local_8 + 0x84 + iVar4 * 4) * local_c + iVar2;
    if (_DAT_0067343c < ABS(*param_3)) {
      FUN_006369f9((double)(float)fVar5);
      iVar2 = __ftol();
      sVar1 = *(short *)(*(int *)(local_8 + 0x48 + iVar4 * 4) + iVar2 * 2);
      iVar2 = __ftol();
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + iVar2 + sVar1;
      iVar2 = __ftol();
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) - iVar2;
    }
  }
  return;
}

