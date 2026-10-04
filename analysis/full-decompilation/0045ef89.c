
int __thiscall FUN_0045ef89(int param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  
  iVar1 = param_2[1] >> 4;
  if (-1 < (char)iVar1) {
    iVar1 = (int)(char)iVar1;
    if (((iVar1 < *(int *)(param_1 + 0x10)) && (cVar2 = (char)(*param_2 >> 4), -1 < cVar2)) &&
       (iVar1 = (int)cVar2, iVar1 < *(int *)(param_1 + 0x10))) {
      return (uint)(uint3)(cVar2 >> 7) << 8;
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

