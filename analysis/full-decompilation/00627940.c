
void FUN_00627940(byte *param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  if (0 < param_3) {
    do {
      if (param_2 == 1) {
        bVar1 = param_1[1];
        bVar2 = *param_1;
        bVar3 = bVar1;
        if (bVar1 <= bVar2) {
          bVar3 = bVar2;
        }
        bVar4 = param_1[2];
        if ((bVar4 <= bVar3) && (bVar4 = bVar2, bVar2 < bVar1)) {
          bVar4 = bVar1;
        }
        param_1[3] = bVar4;
      }
      else {
        bVar1 = param_1[3];
        *param_1 = bVar1;
        param_1[1] = bVar1;
        param_1[2] = bVar1;
      }
      param_1 = param_1 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

