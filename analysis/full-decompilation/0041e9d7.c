
void FUN_0041e9d7(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  do {
    if (param_3 <= *param_1) {
      do {
        piVar3 = param_2;
        param_2 = piVar3 + -2;
      } while (param_3 < *param_2);
      if (param_2 <= param_1) {
        return;
      }
      iVar1 = *param_1;
      iVar2 = param_1[1];
      *param_1 = *param_2;
      param_1[1] = piVar3[-1];
      *param_2 = iVar1;
      piVar3[-1] = iVar2;
    }
    param_1 = param_1 + 2;
  } while( true );
}

