
void FUN_004222ef(uint param_1,int *param_2,int *param_3)

{
  switch(param_1 & 7) {
  case 1:
    *param_2 = *param_2 + 1;
  case 0:
    param_2 = param_3;
    break;
  case 3:
    *param_3 = *param_3 + 1;
  case 2:
    param_3 = param_2;
    goto LAB_00422320;
  case 5:
    *param_2 = *param_2 + -1;
  case 4:
LAB_00422320:
    *param_3 = *param_3 + 1;
    return;
  case 7:
    *param_3 = *param_3 + -1;
  case 6:
    break;
  default:
    goto LAB_0042232e;
  }
  *param_2 = *param_2 + -1;
LAB_0042232e:
  return;
}

