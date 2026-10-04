
void FUN_00474c80(ushort *param_1,ushort *param_2)

{
  if ((param_1 != (ushort *)0x0) && (*param_1 != 0xffff)) {
    *param_1 = *param_1 & 0x7fff;
  }
  if (param_2 != (ushort *)0x0) {
    *param_2 = *param_2 & 0x7fff;
  }
  FUN_00474cae(param_1);
  return;
}

