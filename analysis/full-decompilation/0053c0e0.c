
void FUN_0053c0e0(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  
  cVar1 = DAT_006e4822;
  cVar2 = DAT_006e4823;
  if ((((param_1 == 1) || (cVar1 = DAT_006e481c, cVar2 = DAT_006e481d, param_1 == 2)) ||
      (cVar1 = DAT_006e4825, cVar2 = DAT_006e4826, param_1 == 4)) ||
     (cVar1 = DAT_006e481f, cVar2 = DAT_006e4820, param_1 == 8)) {
    *param_2 = *param_2 + cVar1;
    param_2[1] = param_2[1] + cVar2;
  }
  return;
}

