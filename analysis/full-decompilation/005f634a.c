
void __thiscall FUN_005f634a(int *param_1,int param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 local_14;
  undefined4 local_10;
  int *local_c;
  undefined4 local_8;
  
  if ((char)param_1[0x41] == '\0') {
    *(undefined1 *)(param_1 + 0x41) = 1;
    if (param_2 == param_1[0x38]) {
      *(undefined1 *)(param_1 + 0x41) = 0;
    }
    else {
      if (param_1[0x37] < param_2) {
        param_2 = param_1[0x37];
      }
      if (param_2 < param_1[0x36]) {
        param_2 = param_1[0x36];
      }
      param_1[0x38] = param_2;
      (**(code **)(*param_1 + 0x1c4))();
      puVar1 = (undefined4 *)param_1[0x12];
      if (puVar1 != (undefined4 *)0x0) {
        cVar2 = FUN_005da398(puVar1);
        if (cVar2 != '\0') {
          local_8 = 0;
          local_14 = 3;
          local_10 = 0xc;
          local_c = param_1;
          (**(code **)*puVar1)(&local_14);
        }
      }
      *(undefined1 *)(param_1 + 0x41) = 0;
      (**(code **)(*param_1 + 0x168))();
    }
  }
  return;
}

