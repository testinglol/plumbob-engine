
void __thiscall FUN_005de11f(int *param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  cVar1 = (**(code **)(*param_1 + 0x8c))(1);
  if (cVar1 != '\0') {
    local_14 = param_1[3];
    local_10 = param_1[4];
    local_c = param_1[5];
    local_8 = param_1[6];
    FUN_005de841(&local_14,param_2);
    if ((((local_14 != param_1[3]) || (local_c != param_1[5])) || (local_10 != param_1[4])) ||
       (local_8 != param_1[6])) {
      (**(code **)(*param_1 + 0x168))();
      piVar2 = *(int **)param_1[0xe];
      if (piVar2 != (int *)param_1[0xe]) {
        do {
          (**(code **)(*(int *)piVar2[2] + 0x170))(param_2);
          piVar2 = (int *)*piVar2;
        } while (piVar2 != (int *)param_1[0xe]);
      }
    }
  }
  return;
}

