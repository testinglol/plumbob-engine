
int __thiscall FUN_00484ba0(int param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  
  iVar1 = (int)(char)(param_2[1] >> 4);
  if ((*(int *)(param_1 + 0x70) + 1 <= iVar1) && (iVar1 <= *(int *)(param_1 + 0x74) + -1)) {
    cVar2 = (char)(*param_2 >> 4);
    iVar1 = (int)cVar2;
    if ((*(int *)(param_1 + 0x78) + 1 <= iVar1) && (iVar1 <= *(int *)(param_1 + 0x7c) + -1)) {
      return (uint)(uint3)(cVar2 >> 7) << 8;
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

