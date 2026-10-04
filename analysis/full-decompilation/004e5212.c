
void FUN_004e5212(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  
  do {
    if (param_3 <= *param_1) {
      do {
        param_2 = param_2 + -1;
      } while (param_3 < *param_2);
      if (param_2 <= param_1) {
        return;
      }
      iVar1 = *param_1;
      *param_1 = *param_2;
      *param_2 = iVar1;
    }
    param_1 = param_1 + 1;
  } while( true );
}

