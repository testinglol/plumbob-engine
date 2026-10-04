
undefined8 FUN_005a9890(longlong *param_1,longlong *param_2,uint param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  
  if (((uint)param_1 & 7) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      lVar6 = *param_2;
      param_2 = (longlong *)((int)param_2 + 1);
      *(char *)param_1 = (char)lVar6;
      param_1 = (longlong *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      lVar6 = *param_2;
      param_2 = (longlong *)((int)param_2 + 2);
      *(short *)param_1 = (short)lVar6;
      param_1 = (longlong *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      lVar6 = *param_2;
      param_2 = (longlong *)((int)param_2 + 4);
      *(int *)param_1 = (int)lVar6;
      param_1 = (longlong *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
  }
  while (-1 < (int)(param_3 - 0x80)) {
    lVar6 = param_2[4];
    lVar1 = param_2[8];
    lVar2 = param_2[0xc];
    lVar3 = param_2[2];
    lVar4 = param_2[1];
    lVar5 = param_2[3];
    *param_1 = (longlong)ROUND((float10)*param_2);
    param_1[1] = (longlong)ROUND((float10)lVar4);
    param_1[2] = (longlong)ROUND((float10)lVar3);
    param_1[3] = (longlong)ROUND((float10)lVar5);
    lVar3 = param_2[6];
    lVar4 = param_2[5];
    lVar5 = param_2[7];
    param_1[4] = (longlong)ROUND((float10)lVar6);
    param_1[5] = (longlong)ROUND((float10)lVar4);
    param_1[6] = (longlong)ROUND((float10)lVar3);
    param_1[7] = (longlong)ROUND((float10)lVar5);
    lVar6 = param_2[10];
    lVar3 = param_2[9];
    lVar4 = param_2[0xb];
    param_1[8] = (longlong)ROUND((float10)lVar1);
    param_1[9] = (longlong)ROUND((float10)lVar3);
    param_1[10] = (longlong)ROUND((float10)lVar6);
    param_1[0xb] = (longlong)ROUND((float10)lVar4);
    lVar6 = param_2[0xe];
    lVar1 = param_2[0xd];
    lVar3 = param_2[0xf];
    param_1[0xc] = (longlong)ROUND((float10)lVar2);
    param_1[0xd] = (longlong)ROUND((float10)lVar1);
    param_1[0xe] = (longlong)ROUND((float10)lVar6);
    param_1[0xf] = (longlong)ROUND((float10)lVar3);
    param_2 = param_2 + 0x10;
    param_1 = param_1 + 0x10;
    param_3 = param_3 - 0x80;
  }
  while (-1 < (int)(param_3 - 0x20)) {
    lVar6 = param_2[1];
    *param_1 = (longlong)ROUND((float10)*param_2);
    param_1[1] = (longlong)ROUND((float10)lVar6);
    lVar6 = param_2[3];
    param_1[2] = (longlong)ROUND((float10)param_2[2]);
    param_1[3] = (longlong)ROUND((float10)lVar6);
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = (longlong)ROUND((float10)*param_2);
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (3 < param_3) {
    lVar6 = *param_2;
    param_2 = (longlong *)((int)param_2 + 4);
    *(int *)param_1 = (int)lVar6;
    param_1 = (longlong *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    lVar6 = *param_2;
    param_2 = (longlong *)((int)param_2 + 2);
    *(short *)param_1 = (short)lVar6;
    param_1 = (longlong *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    lVar6 = *param_2;
    param_2 = (longlong *)((int)param_2 + 1);
    *(char *)param_1 = (char)lVar6;
    param_1 = (longlong *)((int)param_1 + 1);
  }
  return CONCAT44(param_2,param_1);
}

