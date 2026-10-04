
uint __thiscall FUN_004355c7(int *param_1,uint *param_2,undefined4 param_3,int param_4,int param_5)

{
  uint in_EAX;
  char cVar1;
  char cVar2;
  int iVar3;
  
  DAT_006e4a7c = 0;
  DAT_006e4a80 = 0;
  cVar2 = (char)((int)param_2[1] >> 4);
  if ((((cVar2 < '\x01') ||
       (iVar3 = *(int *)(DAT_006e54dc + 0x10) + -1, in_EAX = DAT_006e54dc, iVar3 <= cVar2)) ||
      (cVar1 = (char)((int)*param_2 >> 4), cVar1 < '\x01')) ||
     ((iVar3 <= cVar1 ||
      ((DAT_006e4a84 == 0 &&
       (in_EAX = 0,
       (~*(byte *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x34) + 0xc) + cVar2 * 4) + (int)cVar1)
       & 0x20) == 0)))))) {
    DAT_006e4a7c = 1;
  }
  else {
    in_EAX = (**(code **)(*param_1 + 0x54))(param_2,param_3,param_4,param_5);
    if ((((char)in_EAX != '\0') && (in_EAX = param_2[1] & 0xf, (char)in_EAX == '\b')) &&
       (in_EAX = *param_2 & 0xf, (char)in_EAX == '\b')) {
      if ((DAT_006e4a84 == 0) && (param_4 != 0)) {
        if ((param_5 < 0) ||
           ((*(int *)(param_4 + 0x134) - *(int *)(param_4 + 0x130)) / 0x24 + -1 <= param_5)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(param_4 + 0x130) + (param_5 * 9 + 9) * 4;
        }
        in_EAX = 0;
        if (((iVar3 != 0) && (in_EAX = *(uint *)(iVar3 + 0x14), 4 < (int)in_EAX)) &&
           ((int)in_EAX < 8)) {
          DAT_006e4a7c = 0xb;
          goto LAB_00435640;
        }
      }
      return CONCAT31((int3)(in_EAX >> 8),1);
    }
  }
LAB_00435640:
  return in_EAX & 0xffffff00;
}

