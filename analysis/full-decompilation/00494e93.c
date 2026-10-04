
void FUN_00494e93(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  
  cVar4 = *param_2;
  cVar5 = param_2[1];
  cVar1 = param_2[2];
  if (((param_3 == 0) || (param_3 == 2)) || (param_3 == 4)) {
    cVar2 = (&DAT_006e481c)[param_3 * 3];
    cVar3 = (&DAT_006e481d)[param_3 * 3];
  }
  else {
    cVar2 = DAT_006e481c;
    cVar3 = DAT_006e481d;
    if ((param_3 != 6) && (cVar2 = DAT_006e4822, cVar3 = DAT_006e4823, param_3 != 7))
    goto LAB_00494ef2;
  }
  cVar4 = cVar4 + cVar2;
  cVar5 = cVar5 + cVar3;
LAB_00494ef2:
  param_1[1] = cVar5;
  *param_1 = cVar4;
  param_1[2] = cVar1;
  return;
}

