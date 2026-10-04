
int __thiscall FUN_0060aefc(int *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_3 < 1) {
    iVar3 = 0;
  }
  else {
    do {
      bVar1 = *param_2;
      param_2 = param_2 + 1;
      iVar3 = iVar3 + 1;
      if (bVar1 < 0x20) {
        return iVar3;
      }
      if (*param_2 < 0x20) {
        return iVar3;
      }
      cVar2 = (**(code **)(*param_1 + 0x30))(bVar1);
      if (cVar2 != '\0') {
        return iVar3;
      }
    } while (iVar3 < param_3);
  }
  return iVar3;
}

