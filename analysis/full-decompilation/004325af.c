
uint __thiscall FUN_004325af(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  cVar1 = *param_2;
  iVar3 = (int)param_2[2];
  if (-1 < cVar1) {
    if ((int)cVar1 < *(int *)(param_1 + 0x10)) {
      cVar2 = param_2[1];
      param_2 = (char *)CONCAT31((int3)((uint)param_2 >> 8),cVar2);
      if ((((-1 < cVar2) && (param_2 = (char *)(int)cVar2, (int)param_2 < *(int *)(param_1 + 0x10)))
          && (0 < iVar3)) && (iVar3 < 3)) {
        return CONCAT22(cVar2 >> 7,
                        *(undefined2 *)
                         (*(int *)(*(int *)(*(int *)(param_1 + 0x38 + iVar3 * 4) + 0xc) + cVar1 * 4)
                         + (int)param_2 * 2));
      }
    }
  }
  return (uint)param_2 & 0xffff0000;
}

