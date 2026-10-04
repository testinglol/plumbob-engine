
void FUN_00623b80(int param_1,char *param_2,int param_3,int param_4,char param_5,char param_6,
                 int *param_7,int param_8)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  for (iVar1 = param_3 / param_4; iVar3 = param_3 / param_4, iVar1 != 0; iVar1 = iVar1 + -1) {
    do {
      if (((*param_2 == param_5) || (*param_2 == param_6)) &&
         ((cVar2 = *(char *)(*param_7 + param_1), cVar2 == param_5 || (cVar2 == param_6)))) {
        *param_2 = cVar2;
      }
      param_7 = param_7 + 1;
      param_2 = param_2 + param_4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    param_2 = param_2 + (param_4 * param_8 - param_3);
  }
  return;
}

