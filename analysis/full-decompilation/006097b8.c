
void FUN_006097b8(byte param_1,int *param_2,int param_3,undefined1 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  *(byte *)(*param_2 + 8 + (int)param_2) = param_1;
  cVar1 = (&DAT_006d99bc)[param_1];
  iVar3 = (int)cVar1;
  iVar2 = ((char)(&DAT_006d98bc)[param_1] - iVar3) + param_3;
  if (param_2[1] < iVar2) {
    param_2[1] = iVar2;
  }
  if (param_3 < iVar3) {
    param_2[1] = param_2[1] + (iVar3 - param_3);
    param_3 = param_3 + (iVar3 - param_3);
  }
  *(char *)(*param_2 + 0xb + (int)param_2) = (char)param_3 - cVar1;
  *(undefined1 *)(*param_2 + 0xe + (int)param_2) = param_4;
  *param_2 = *param_2 + 1;
  return;
}

