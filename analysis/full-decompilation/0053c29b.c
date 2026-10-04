
void __thiscall FUN_0053c29b(char *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  char local_8;
  char local_7;
  
  uVar2 = param_2 - *(int *)(param_1 + 4) & 3;
  FUN_00434ffd();
  cVar1 = DAT_006e4820;
  local_8 = (char)param_1;
  local_7 = (char)((uint)param_1 >> 8);
  if (uVar2 == 1) {
    FUN_00461b74();
    *param_1 = *param_1 + local_8;
  }
  else {
    if (uVar2 != 2) {
      if (uVar2 == 3) {
        *param_1 = *param_1 + DAT_006e481f;
        param_1[1] = param_1[1] + cVar1;
      }
      goto LAB_0053c300;
    }
    FUN_00461b74();
    *param_1 = *param_1 + local_8;
  }
  param_1[1] = param_1[1] + local_7;
LAB_0053c300:
  if ((((uVar2 != 0) &&
       (param_1[8] = (&DAT_006f4b20)[(uint)(byte)param_1[8] + uVar2 * 0x100], uVar2 != 0)) &&
      (param_1[9] = (&DAT_006f4b20)[(uint)(byte)param_1[9] + uVar2 * 0x100], uVar2 != 0)) &&
     (param_1[10] = (&DAT_006f4b20)[(uint)(byte)param_1[10] + uVar2 * 0x100], uVar2 != 0)) {
    param_1[0xb] = (&DAT_006f4b20)[(uint)(byte)param_1[0xb] + uVar2 * 0x100];
  }
  if (uVar2 != 0) {
    param_1[0xc] = (&DAT_006f4b20)[(uint)(byte)param_1[0xc] + uVar2 * 0x100];
  }
  FUN_0053d3e3(param_1 + 0x10);
  FUN_00438c54(param_1 + 10);
  cVar1 = FUN_0053cf03();
  param_1[0x24] = cVar1;
  FUN_00438c54(param_1 + 9);
  cVar1 = FUN_0053cf03();
  param_1[0x25] = cVar1;
  *(int *)(param_1 + 4) = param_2;
  return;
}

