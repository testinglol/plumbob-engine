
int __thiscall FUN_004b3863(int param_1,char *param_2)

{
  char cVar1;
  undefined4 in_EAX;
  int iVar2;
  
  cVar1 = *param_2;
  iVar2 = CONCAT31((int3)((uint)in_EAX >> 8),cVar1);
  if (-1 < cVar1) {
    iVar2 = (int)cVar1;
    if (((iVar2 < *(int *)(param_1 + 0x10)) && (cVar1 = param_2[1], -1 < cVar1)) &&
       (iVar2 = (int)cVar1, iVar2 < *(int *)(param_1 + 0x10))) {
      return (uint)(uint3)(cVar1 >> 7) << 8;
    }
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}

