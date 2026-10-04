
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004ca342(int param_1,int param_2,int param_3)

{
  float fVar1;
  undefined2 uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  tagRECT local_20;
  int *local_10;
  undefined8 local_c;
  
  iVar3 = (int)(0x194 / (longlong)(1 << (3 - (byte)param_3 & 0x1f)));
  iVar6 = iVar3 * 2;
  local_c._4_4_ = param_1;
  pvVar4 = operator_new(iVar3 * 4);
  *(void **)(param_1 + (4 - param_3) * 4) = pvVar4;
  local_10 = (int *)(param_1 + (4 - param_3) * 4);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0x9b0b0001;
  }
  else {
    iVar3 = *(int *)(param_2 + 4);
    local_20.left = *(int *)(iVar3 + 0x68);
    local_20.top = *(int *)(iVar3 + 0x6c);
    local_20.right = *(LONG *)(iVar3 + 0x70);
    local_20.bottom = *(LONG *)(iVar3 + 0x74);
    OffsetRect(&local_20,-local_20.left,-local_20.top);
    fVar1 = *(float *)(local_c._4_4_ + (0x1b - param_3) * 4);
    local_c = (double)(fVar1 + fVar1);
    FUN_00636264(_DAT_006682f8);
    iVar3 = 0;
    local_c = (double)CONCAT44((float)((iVar6 - (8 << ((byte)param_3 & 0x1f))) + -1),
                               SUB84(local_c,0));
    if (0 < iVar6) {
      do {
        uVar2 = __ftol();
        *(undefined2 *)(*local_10 + iVar3 * 2) = uVar2;
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar6);
    }
    *(short *)*local_10 = *(short *)*local_10 + 0x41;
    uVar5 = 0;
  }
  return uVar5;
}

