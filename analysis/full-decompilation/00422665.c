
int __thiscall FUN_00422665(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  iVar1 = param_2[1] >> 4;
  if ('\0' < (char)iVar1) {
    iVar1 = (int)(char)iVar1;
    iVar2 = *(int *)(param_1 + 0x10) + -1;
    if (((iVar1 < iVar2) && (cVar3 = (char)(*param_2 >> 4), '\0' < cVar3)) &&
       (iVar1 = (int)cVar3, iVar1 < iVar2)) {
      return (uint)(uint3)(cVar3 >> 7) << 8;
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

