
void FUN_0044a6d4(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,code *param_4)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *local_24;
  undefined4 *local_1c;
  undefined4 *local_18;
  int local_14;
  
  uVar1 = *param_2;
  cVar2 = (*param_4)(uVar1,*param_1);
  if (cVar2 == '\0') {
    while( true ) {
      local_24 = param_2 + -1;
      cVar2 = (*param_4)(uVar1,*local_24);
      if (cVar2 == '\0') break;
      *param_2 = *local_24;
      param_2 = local_24;
    }
    *param_2 = uVar1;
  }
  else {
    local_1c = param_2 + 1;
    local_18 = param_2;
    for (local_14 = (int)param_2 - (int)param_1 >> 2; 0 < local_14; local_14 = local_14 + -1) {
      local_18 = local_18 + -1;
      local_1c = local_1c + -1;
      *local_1c = *local_18;
    }
    *param_1 = uVar1;
  }
  return;
}

