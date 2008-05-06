/*
 * Copyright (C) 2006 Tommi Maekitalo
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * is provided AS IS, WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, and
 * NON-INFRINGEMENT.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 *
 */

#include <zeno/article.h>
#include <cxxtools/log.h>

log_define("zeno.article")

namespace zeno
{
  const std::string& Article::getRawData() const
  {
    log_trace("getRawData()");

    if (!dataRead)
    {
      Article* article = const_cast<Article*>(this);
      log_debug("read data from file");
      article->setRawData(const_cast<File&>(file).readData(getDirent().getOffset(),
        getDirent().getSize()));
      article->dataRead = true;
    }

    return ArticleBase::getRawData();
  }

}
